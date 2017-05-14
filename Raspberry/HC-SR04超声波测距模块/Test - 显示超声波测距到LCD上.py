import RPi.GPIO as GPIO
from time import sleep, time
import Adafruit_CharLCD as LCD

TRIG = 11
ECHO = 13

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

GPIO.setmode(GPIO.BOARD)
GPIO.setup(TRIG, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(ECHO, GPIO.IN)
lcd = LCD.Adafruit_CharLCDPlate()

try:
    while True:
        lcd.message('distance: %0.2f cm' % checkdist())
        sleep(0.1)
except KeyboardInterrupt:
    GPIO.cleanup()
