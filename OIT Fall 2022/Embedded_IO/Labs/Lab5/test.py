#On Chip Datalogger
#
#import libraries machine and utime
import machine
import utime
led_onboard = machine.Pin(25,machine.Pin.OUT);
button = machine.Pin(15, machine.Pin.IN, machine.Pin.PULL_UP)
adc_in0 = machine.ADC(26)#assign ADC channel 0 (physical pin 31) to adc_in0
led_onboard.off()
#Run code if switch IS PRESSED. Press switch for one second.
while (button.value() == 1):#Loop here if switch not pressed
        print(button.value())
        utime.sleep(1)
              
#adc_in0 = machine.ADC(26)#assign ADC channel 0 (physical pin 31) to adc_in0
conversion_factor = 3.3/(65535) #converts ADC number to a voltage
file = open("volts.txt","w")#creates and opens for writing a file named "volts.txt"
for i in range (100):#(600):#number of minutes to collect data
    reading = adc_in0.read_u16()*conversion_factor
    print("reading = ",reading)
    file.write(str(reading)+"\n")
    file.flush()
    
    #for loop loops for one minute
    for i in range (1):#(480):# blinks on board led on and off while code is running
        led_onboard.toggle()
        utime.sleep(0.125)
    
file.close()
print("Done")