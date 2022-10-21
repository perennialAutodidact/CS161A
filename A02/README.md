# CS 161A: Programming and Problem Solving I - Assignment A02

## Description

This program will estimate the number of jellybeans that could fit inside a jar. The user will enter the height and width of a single jelly bean in centimeters as well as the volume of the jar in millileters and output an approximation of the number of jellybeans of the given size that could fit into a jar of the given volume.

## Sample run

```
Let's guess how many jelly beans will fit into a jar!
Enter the length of one jelly bean (cm):
1.52
Enter the height of one jelly bean (cm):
0.9
Enter the volume of the jar (mL):
500
Approximately 433 jelly beans could fit in a jar with a volume of 500 mL.
```

```
Let's guess how many jelly beans will fit into a jar!
Enter the length of one jelly bean (cm):
1.2
Enter the height of one jelly bean (cm):
0.5
Enter the volume of the jar (mL):
255
Approximately 906 jelly beans could fit in a jar with a volume of 255 mL.
```

## Input

`jellyBeanWidth` as float

`jellyBeanHeight` as float

`jarVolume` as integer

### Constant values

`LOAD_FACTOR` as float (this is the amount of space inside the jar occupied by jellybeans and will not be entered by the user)

## Output

`totalJellyBeans` as integer

## Calculations

Volumn of one jelly bean:

`jellyBeanVol = (5 * PI * (jellyBeanHeight * jellyBeanWidth^2)) / 24`

Total number of jelly beans that would fit in the jar:

`totalJellybeans = jarVolume * LOAD_FACTOR / jellyBeanVol`

## Pseudocode

```
DECLARE variables jellyBeanWidth, jellyBeanHeight and jellyBeanVol as float

DECLARE variable LOAD_FACTOR as a float constant and initialize to 0.698

DECLARE variables jarVolume and totalJellyBeans as integers

DISPLAY Welcome message

DISPLAY prompt - Enter the height of one jelly bean:

INPUT into jellyBeanHeight

DISPLAY prompt - Enter the width of one jelly bean:

INPUT into jellyBeanWidth

DISPLAY prompt - Enter the volume of the jar:

INPUT into jarVolume

SET jellyBeanVol = (5 _ PI _ (jellyBeanHeight \* jellyBeanWidth^2)) / 24

SET totalJellyBeans = jarVolume \* LOAD_FACTOR / jellyBeanVol

DISPLAY The number of jelly beans that could fit into the jar is {totalJellyBeans}
```
