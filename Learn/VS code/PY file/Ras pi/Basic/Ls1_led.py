import RPi.GPIO as GPIO
import time

ans = 'Y'
GPIO.setmode(GPIO.BOARD)
GPIO.setup(11,GPIO.OUT)
while ans == 'Y':
    num = int(input('How many blinks do you want: '))
    for i in range(0,num):
        GPIO.output(11,1)
        time.sleep(1)
        GPIO.output(11,0)
        time.sleep(1)
    ans=input("Do you want to continue(Y/N): ")
GPIO.cleanup()