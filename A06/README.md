# CS 161A: Programming and Problem Solving I - Assignment A06

## Description

This program will estimate the number of jelly beans that can fit in a jar. The user will be prompted for the width and length of one jelly bean as well as the volume of the jar and the program will tell them how many jelly beans could fit in the jar. The program will repeat until the user decides to exit and will display the total number of entries, the average number of jelly beans per entry, the largest jelly bean and the jar size for the largest jelly bean estimation. 

## Sample Run

```
******************************************************

Let's guess how many jelly beans will fit into a jar!

******************************************************

Enter the length and width of one jelly bean in centimeters, separated by a space:
> 1.2 0.75

Enter the volume of the jar (mL):
> 300

Approximately 473 jelly beans could fit in a jar with a volume of 300 mL.

Do you want to estimate again? y/n:
> y

Okay, let's continue!


Enter the length and width of one jelly bean in centimeters, separated by a space:
> 2.1 1.3

Enter the volume of the jar (mL):
> 700

Approximately 210 jelly beans could fit in a jar with a volume of 700 mL.

Do you want to estimate again? y/n:
> y

Okay, let's continue!


Enter the length and width of one jelly bean in centimeters, separated by a space:
> 0.9 1.1

Enter the volume of the jar (mL):
> 200

Approximately 195 jelly beans could fit in a jar with a volume of 200 mL.

Do you want to estimate again? y/n:
> n
Number of entries: 3
Average number of jelly beans: 292.67
Largest jelly bean: 2.32 cm^3
Jar size for largest jelly bean estimate: 300 mL.
```
```
******************************************************

Let's guess how many jelly beans will fit into a jar!

******************************************************

Enter the length and width of one jelly bean in centimeters, separated by a space:
> 1.5 0.9

Enter the volume of the jar (mL):
> 500

Approximately 438 jelly beans could fit in a jar with a volume of 500 mL.

Do you want to estimate again? y/n:
> y

Okay, let's continue!

Enter the length and width of one jelly bean in centimeters, separated by a space:
> 2.0 1.0

Enter the volume of the jar (mL):
> 25

Approximately 13 jelly beans could fit in a jar with a volume of 25 mL.

Do you want to estimate again? y/n:
> y

Okay, let's continue!


Enter the length and width of one jelly bean in centimeters, separated by a space:
> 1.9 1.3

Enter the volume of the jar (mL):
> 250

Approximately 83 jelly beans could fit in a jar with a volume of 250 mL.

Do you want to estimate again? y/n:
> n

Number of entries: 3
Average number of jelly beans: 178.00
Largest jelly bean: 2.10 cm^3
Jar size for largest jelly bean estimate: 500 mL.
```

## Inputs
- `jarVolume` as integer (to store the jar volume)
- `jellyBeanHeight` as double (to store the jelly bean width)
- `jellyBeanLength` as double (to store the jelly bean length)
- `userInput` as char (to store the user’s choice to continue or exit)

## Outputs
- `jellyBeanVol` as double (to store the volume of the current jelly bean)
- `totalEntries` as integer (to track how many loops have occurred)
- `jellyBeanAvg` as double (to store the average number of jelly beans per entry)
- `jellyBeanVolLargest` as double (to store the volume of the largest jelly bean)
- `jarVolLargestEstimate` as integer (to store the jar volume of the largest estimate)

## Calculations
- jelly bean volume formula: `(5 * PI * (jellyBeanHeight * jellyBeanWidth^2)) / 24`
- jelly beans in jar formula: `jarVolume * LOAD_FACTOR / jellyBeanVol`
- Division to find the average 
- Static_cast to convert to double while dividing
- Conditional statements to find 
  - jar volume of largest estimation
  - jelly bean of largest volume

```
DECLARE const LOAD_FACTOR = 0.698
DECLARE const PI = 3.14…

DECLARE integer jarVolume, jellyBeanTotal, totalEntries, jellyBeanLargestTotal, jarVolLargestEstimate

DECLARE double jellyBeanHeight, jellyBeanLength, jellyBeanVol, jellyBeanAvg, jellyBeanSum, jellyBeanVolLargest

DECLARE boolean shouldContinue
DECLARE char userInput

DISPLAY welcome message

DO
    DISPLAY “Enter the height and length of a jelly bean (separated by a space)”
    INPUT into jellyBeanHeight and jellyBeanLength
    
    DISPLAY “Enter the volume of the jar”
    INPUT into jarVolume
    SET jellyBeanVol = (5 * PI * (jellyBeanLength * pow(jellyBeanHeight, 2))) / 24
    SET jellyBeanTotal = jarVolume * LOAD_FACTOR
    SET jellyBeanSum = jellyBeanSum + jellyBeanVol
    IF jellyBeanVol > jellyBeanVolLargest
        SET jellyBeanVolLargest = jellyBeanVol
    END IF
    DISPLAY “{jellyBeanTotal} jelly beans would fit in the jar”
    
    DISPLAY “Do you want to continue”?
    INPUT into userInput

    WHILE userInput != ‘y’ AND userInput != ‘n’
        DISPLAY “Invalid input”
        INPUT into userInput
    END WHILE

    IF userInput == ‘y’
        DISPLAY “Okay, let’s continue”
        SET totalEntries = totalEntries + 1
        IF jellyBeanTotal > jellyBeanLargestTotal
            SET jellyBeanLargestTotal = jellyBeanTotal
            SET jarVolLargestEstimate = jarVolume
        END IF

    ELSE IF userInput == ‘n’
        SET shouldContinue = false
        SET jellyBeanAvg = static_cast<double>(jellyBeanSum) / totalEntries
    END IF

WHILE shouldContinue = true

DISPLAY “Number of entries: {totalEntries}”
DISPLAY “Average jelly beans: {jellyBeanAvg}”
DISPLAY “Largest jelly bean: {jellyBeanVolLargest} cm^3”
DISPLAY “Jar size for largest estimate: {jarVolLargestEstimate} mL”

END
```
