# Firefighting-Robot

• We have a fire fighting robot.
• It keeps moving until power off switch is used to turn it off. It uses three “Ultrasonic Ranging Module HC -
SR04“to check front, right and left paths. If it detects any obstacles in front, it checks right if it is clear, it turns
right. Otherwise, it turns left. Add voltage source for each ultrasonic sensor to simulate the distance. It uses
two stepper motors to move forward, turn right or left. If both motors ON, it keeps moving forward. Stopping
one motor and moving the other motor one full rotation, making the robot rotate with 45o degrees to the
rotated stepper motor direction.
• The robot searches for fire. It uses Digital fire detector sensor (Replaced with a switch). If the sensor detects
fire, it sends HIGH for half a second then returns back to LOW. If it is HIGH for less than half a second then it
is not fire and the fighting system should not work. It is just sensor hazard.
• This robot has a fire fighting fan to vanquish fire (appears as a stepper motor). If the robot detects fire it must
stop moving and the fan motor should keep rotating until receiving HIGH signal – with any interval - from the
Digital fire detector sensor (the switch).
• The robot has a blinking led that blinks every one second.
Note: used components are
o 1 LED: Keep blinking
o 2 switches: power off switch - Digital fire detector sensor
o 3 stepper motors: two stepper motors for moving and one as the fan motor
o 3 Ultrasonic modules: front, right and left
o 3 voltage sources: one for each ultrasonic module
