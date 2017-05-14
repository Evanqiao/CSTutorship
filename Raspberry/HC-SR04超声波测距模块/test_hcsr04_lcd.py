import RPi.GPIO as GPIO
from time import sleep, time
import Adafruit_CharLCD as LCD

lcd = LCD.Adafruit_CharLCDPlate()

TRIG = 17
ECHO = 27

def checkdist():
    GPIO.output(TRIG, GPIO.HIGH)
    sleep(0.000015)
    GPIO.output(TRIG, GPIO.LOW)
    while not GPIO.input(ECHO):
        pass
    t1 = time()
    while GPIO.input(ECHO):
        pass
    t2 = time()
    return (t2 - t1) * 34000 / 2

GPIO.setmode(GPIO.BCM)
GPIO.setup(TRIG, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(ECHO, GPIO.IN)

try:
    while True:
        print('distance:%0.2fcm' % checkdist())
        lcd.clear()
        lcd.message('distance:\n%0.2fcm' % checkdist())
        sleep(1)
except KeyboardInterrupt:
    GPIO.cleanup()
