import machine
import utime

motor = machine.Pin(14, machine.Pin.OUT)
input = machine.Pin(18, machine.Pin.IN)
time1 = 0
time2 = 0
average = 0
while 1:
    for x in range(100):
        time1 = utime.ticks_us()
        while input.value() == 1:
            continue
        while input.value() == 0:
            continue
        period = utime.ticks_diff(utime.ticks_us(), time1)    
        frequency = 1/period * 1000
        average += frequency
    average = average/100
    print(average)
    if average > 3.45:
        motor.value(1)
    else:
        motor.value(0)