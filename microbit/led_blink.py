from microbit import *

delay = 200

def red():
    pin0.write_digital(1)
    pin1.write_digital(0)
    pin2.write_digital(0)

def green():
    pin0.write_digital(0)
    pin1.write_digital(1)
    pin2.write_digital(0)

def blue():
    pin0.write_digital(0)
    pin1.write_digital(0)
    pin2.write_digital(1)

while True:
    red()
    sleep(delay)
    green()
    sleep(delay)
    blue()
    sleep(delay)

