# Automatic EyeGlass Cleaner
Inter IIT Tech Meet 2019

## Abstract

Aim of this project is to make a self-automated Eyeglass Cleaner that can cleanse and dry any spectacles.

![Final Product](https://github.com/SanjeevKrishnan/Automatic-EyeGlass-Cleaner/blob/master/Images%20and%20Videos/Images/Final%20Product.jpeg)

## Motivation

In this fast and busy world, we fail to take care of our own minute personal cleanliness. But when we enter the professional world, all these small things get noticed. And also, these small things pile up to big issues which in turn affects us directly. In this, our spectacles take a major part because eyes are our index. An easily operable machine which can clean our spectacles during our coffee time will be of high use, especially in professional and public spaces.

Eyeglasses cleaners available presently in the market are costly but are not versatile. They either do ultrasonic cleaning or splashing water and drying. But still, it leaves smudges on the lenses. And also they might take much time for this simple task and majorly nowhere automatic wiping is available. This process is clumsy and can be automated which would give the user complete hands-free experience.  

So we planned on designing a machine that can clean, rinse, dry, and wipe the eye-glass in less time.

## Components

* 2x Air Blower
* Capacitors
* 2x Cytron Motor Drive
* 1x DC 900 rpm motor
* 2x DC 300 rpm motor
* 2x DC Solenoid Valve
* Fuse
* Inductors
* 1x 12V DC Power Adapter
* Relay
* 4x 5V Relay Module
* Resistors
* 1x Rotary Encoder
* 1x Servo Motor
* Transformers
* Transistors
* Ultrasonic Transducer
* 1x Water Pump

## Workflow

![Worflow Diagram](https://github.com/SanjeevKrishnan/Automatic-EyeGlass-Cleaner/blob/master/Images%20and%20Videos/Images/Workflow%20Diagram.png)

## Mechanical Aspect of the Design

### Structure

It is a cuboidal frame structure made up of aluminum channel covered with transparent acrylic sheets to allow users to see the whole cleaning process. Wiper and hot air blower are placed at the top, water rinser is placed at the middle, and ultrasonic cleaning vessel is placed at the bottom. Water storage is placed above the structure, ultrasonic circuit, and water pump is placed in a separate chamber below ultrasonic vessel separated by plywood and all other electronic components are placed at the backside of the structure separated from the structure by acrylic sheet to protect components from water.

### Holder

We have designed a special holder for mounting the eyeglasses. Eyeglasses comes in different shapes and sizes. So we have made a holder that can adjust itself to hold all types of eyeglasses.

### Ultrasonic Cleaning

There is a vessel at the bottom which is connected with an ultrasonic transducer which produces ultrasonic waves in the liquid filled inside the vessel by changing electrical signals to mechanical waves. The waves create cavitation in the liquid. These cavitations collapse with enormous energy due to which high temperature and pressure are generated and thus help in cleaning the glasses.

### Rinsing

After ultrasonic cleaning, eye-glass is lifted to the middle of the machine where it is rinsed with water with the help of a ‘U’ shaped structure with two nozzles placed in front and back of the lenses. This rinser runs perpendicular to the eyeglass splashing water on the eyeglasses. 

### Drying and Wiping

After rinsing, eyeglasses move to the last level, to the top of the machine, where it is dried and wiped. There are hot air blowers on the two side walls of the machine which blows hot air on the spectacle which helps in removing wetness from the frame. Then it is wiped with a sponge wrapped with a microfiber cloth. There are 4 circular disks with this kind of wiping material covering both sides of both the lenses. This wiper works on the rack and pinion mechanism.

### Traversal

The eyeglass holder is connected to a vertical lead screw which helps the eye-glass to move to different levels for different processes. This vertical lead screw is operated by a 900 rpm DC motor which is placed perpendicular to the lead screw and both are coupled with a pair of bevel gear. Its feedback is taken with the help of a rotary encoder which is again placed in the same fashion as the motor.

## Electronics Aspect of the Design

### Microcontroller

Arduino Mega 2560 R3 is used as the microcontroller board.

### Sensors

* Rotary Encoder is used to get the coordinate feedback of vertical assembly(holder).
* Hall Sensor is used to sense the home state(start position) of vertical assembly.

### Actuators

* Johnson 900 rpm DC motor is used for traversal of the holder.
* Johnson 300 rpm DC motors are used for traversal of the rinser and movement of wiper.
* Servo Motor is used for wiping action.

### Other Controllers

* Cytron Motor driver is used to control DC motors
* 5V Relay module is used to switch on/off the ultrasonic cleaner, water pump, and air blowers.

### Other Components

* DC 12V 80W water pump is used to spray water during rinsing action.
* 12V Solenoid Valves are used to control water movement between the tank and ultrasonic vessel

### Power

* Ultrasonic Cleaner circuit and air blowers are directly powered from 220V AC supply.
* 12V DC Power Adapter is used to convert 220V AC to 12V DC to power solenoid valves, water pump, and motor drivers.
* IC LM7809, IC LM7806, IC LM7805 are used to convert 12v DC to 9V DC, 6V DC, 5V DC respectively to power Arduino, servo motor, encoder, relay module.

## Cost Structure

| **Components**                    |**Cost(INR.)**|
|-----------------------------------|------------|
| Air Blower                        | 1300       |
| Aluminium Channels and Rods       | 800        |
| Arduino Mega                      | 800        |
| Capacitors                        | 300        |
| Cytron Motor Driver               | 3000       |
| DC Motors                         | 1050       |
| DC Solenoid Valve                 | 250        |
| Fuse                              | 35         |
| Hose, Pipes, and Brass connectors | 450        |
| Inductors                         | 150        |
| Power Adapter                     | 1500       |
| Relay                             | 100        |
| Relay Module                      | 450        |
| Resistors                         | 900        |
| Rotary Encoder                    | 1500       |
| Servo Motor                       | 150        |
| Transformer                       | 230        |
| Transistors                       | 100        |
| Ultrasonic Transducer             | 800        |
| Water Pump                        | 700        |
| Miscellaneous                     | 235        |
| **Total**                         | **14000**  |

## Applications

* Optical showrooms-To clean customers’ spectacles
* Eye clinics - To clean patients’ spectacles
* Theatres - To clean 3D glasses 
* Offices - Workers can clean their spectacles
* Shopping Malls - People can spend their wait time in cleaning their spectacles

## Limitations

* Time taken per eyeglass is bit high.
* Ultrasonic cleaning circuit has to be switched on manually.

## Future Improvements

* Actuations can be made fast to reduce cleaning duration.
* Indications and Error messages can be displayed using an LCD display module.
* Ultrasonic Cleaning process can also be automated.

## Team Members

1. [Panuganti Shiva Sri Teja Kumar](https://github.com/shivasriteja)
2. [Rishika Chandra](https://github.com/chandrarishika14)
3. [Sanjeev Krishnan R.](https://github.com/SanjeevKrishnan)
4. [Suja G.](https://github.com/suja-g)
5. [Yawan Gupta](https://github.com/yawangupta)

## Mentors

1. Anant Shandilya
2. Shubhanshu Agarwal

## References

<https://techblog.ctgclean.com/2012/01/ultrasonics-transducers-resonance/>

<https://www.americanpiezo.com/standard-products/ultrasonic-power-transducers.html>

<https://www.allaboutvision.com/en-in/eyeglasses/faq/eyeglass-frame-size/>

<https://www.svce.ac.in/departments/physics/ph16151/UNIT%204%20Ultrasonics%20.new.pdf>