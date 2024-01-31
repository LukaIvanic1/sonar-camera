import serial
import time


def list_serial_ports():
    ports = serial.tools.list_ports.comports()
    if not ports:
        print("No serial ports found.")
    else:
        print("Available serial ports:")
        for port, desc, hwid in sorted(ports):
            print(f"{port}: {desc} [{hwid}]")

if __name__ == "__main__":
    list_serial_ports()



ser = serial.Serial('COM' + input("Input the # of COM port of ESP32"), 115200, timeout=1)


output_file = open('output.txt', 'w')

try:
    while True:
        
        line = ser.readline()

     
        print(line)

        
        output_file.write(line)

except KeyboardInterrupt:
    ser.close()
    output_file.close()
    print("Serial port and file closed.")
