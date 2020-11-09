from ArduinoDAQ import SerialConnect

portName = 'COM3'                      # Communications port name. Make sure it matches port in Arduino IDE
# portName = '/dev/ttyUSB0'
fileName = 'Demo.csv'                  # File name to save to
baudRate = 19200                      # Baud Rate
dataRate = 150                         # Acquisition data rate (Hz), do no exceed 500
recordTime = 10                        # Number of seconds to record data
numDataPoints = recordTime * dataRate  # Total number of data points to be saved

# Name of data collected from Arduino
# Will be used as column headers in saved file
# NOTE: Time must be first element; ArduinoDAQ module converts from microseconds to seconds
dataNames = ['Time', 'accX', 'accY', 'accZ']

# Corresponding data types
# See https://docs.python.org/2/library/struct.html#format-characters for 
# a list of valid characters
# See https://robotresearchlab.com/2016/11/14/variable-data-types/ for 
# corresponding Arduino types
dataTypes = ['=L', '=h', '=h', '=h']


# initializes all required variables
s = SerialConnect(portName, fileName, baudRate, dataRate, dataNames, dataTypes)

# Connect to Arduino and send over rate
s.connectToArduino()

# Start Recording Data
print("Recording...")

# Collect data
while len(s.dataStore[0]) < numDataPoints:
    s.getSerialData()
    
    # Print number of seconds that have passed
    if len(s.dataStore[0]) % dataRate == 0:
        print(len(s.dataStore[0]) /dataRate)   

# Close Arduino connection and save data
s.close()
