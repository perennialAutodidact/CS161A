# CS 161A: Programming and Problem Solving I - Midterm

## Description
This program will determine the winner of a rock collecting competition by determining which of three players collected the most rocks. The program will prompt for each player’s name and the number of rocks they collected. It will then output the first, second, and third place player and the number of rocks each collected, accounting for ties where players have equal numbers of rocks. Finally, the program will output the average number of rocks collected before exiting. 


## Sample Run
```
Welcome to the Rock Collecting Championship!

Please enter the name of the first contestant:
> George Harrison
How many rocks did George Harrison collect? 17

Please enter the name of the second contestant:
> John Lennon
How many rocks did John Lennon collect? 15

Please enter the name of the third contestant:
> Ringo Starr
How many rocks did Ringo Starr collect? 3
George Harrison is in first place.
John Lennon is in second place.
Ringo Starr is in third place.

The average number of rocks collected by the top three players is 11.67 rocks!

Congratulations Rock Collectors!
```

```
Welcome to the Rock Collecting Championship!

Please enter the name of the first contestant:
> George Harrison
How many rocks did George Harrison collect? -9
Invalid amount! Zero will be entered instead.

Please enter the name of the second contestant:
> John Lennon
How many rocks did John Lennon collect? 19

Please enter the name of the third contestant:
> Ringo Starr
How many rocks did Ringo Starr collect? 12

John Lennon is in second place.
Ringo Starr is in first place.
George Harrison is in second place.

The average number of rocks collected by the top three players is 10.33 rocks!

Congratulations Rock Collectors!Welcome to the Rock Collecting Championship!
```

```
Welcome to the Rock Collecting Championship!

Please enter the name of the first contestant:
> John Lennon
How many rocks did John Lennon collect? 33

Please enter the name of the second contestant:
> George Harrison
How many rocks did George Harrison collect? 66

Please enter the name of the third contestant:
> Ringo Starr
How many rocks did Ringo Starr collect? 66

George Harrison and Ringo Starr are tied for first.
John Lennon is in second place.

The average number of rocks collected by the top three players is 55.00 rocks!

Congratulations Rock Collectors!
```

```
Welcome to the Rock Collecting Championship!

Please enter the name of the first contestant:
> John Lennon
How many rocks did John Lennon collect? 66

Please enter the name of the second contestant:
> George Harrison
How many rocks did George Harrison collect? 33

Please enter the name of the third contestant:
> Ringo Starr
How many rocks did Ringo Starr collect? 33

George Harrison and Ringo Starr are tied for second place. 
John Lennon is in first place.

The average number of rocks collected by the top three players is 44.00 rocks!

Congratulations Rock Collectors!
```

```
Welcome to the Rock Collecting Championship!

Please enter the name of the first contestant:
> John Lennon
How many rocks did John Lennon collect? 33

Please enter the name of the second contestant:
> George Harrison
How many rocks did George Harrison collect? 33

Please enter the name of the third contestant:
> Ringo Starr
How many rocks did Ringo Starr collect? 33

All contestants are tied with 33 rock(s).

The average number of rocks collected by the top three players is 33.00 rocks!
```

## Inputs
- `player1` as string
- `player2` as string
- `player3` as string
- `rockCount1` as integer
- `rockCount2` as integer
- `rockCount3` as integer

## Outputs
- `rockAverage` as double
- a message indicating each player’s placement. No variable for this.

## Calculations
- `const int NUM_CONTESTANTS = 3`
- `int rockTotal = rockCount1 + rockCount2 + rockCount3`
- `rockAverage = static_cast<double>(rockTotal) / NUM_PLAYERS`
- conditional statements comparing the player’s counts

### Win / Lose / Tie Cases

All tied 

1 first, 2 and 3 tied for second
2 first, 1 and 3 tied for second
3 first, 1 and 2 tied for second

1 and 2 tied for first, 3 second
2 and 3 tied for first, 1 second
1 and 3 tied for first, 2 second

1 first, 2 second, 3 third
1 first, 3 second, 2 third
2 first, 1 second, 3 third
2 first, 3 second, 1 third
3 first, 1 second, 2 third
3  first, 2 second, 3 third

## Pseudocode
```
DECLARE const int NUM_PLAYERS = 3
DECLARE string player1, player2, player3
DECLARE int rockCount1 = 0, rockCount2 = 0, rockCount3 = 0
DECLARE int totalRocks
DECLARE double rockAverage

DISPLAY welcome message

DISPLAY PROMPT “Enter the name of player 1”
INPUT into player1

DISPLAY PROMPT “How many rocks did {player1} collect?”
INPUT into rockCount1
IF rockCount1 < 0
    DISPLAY “Invalid input. Zero will be entered.”
    SET rockCount1 = 0
ENDIF

DISPLAY PROMPT “Enter the name of player 2”
INPUT into player2

DISPLAY “How many rocks did {player2} collect?”
INPUT into rockCount2
IF rockCount2 < 0
    DISPLAY “Invalid input. Zero will be entered.”
    SET rockCount2 = 0
ENDIF

DISPLAY PROMPT “Enter the name of player 3”
INPUT into player3

DISPLAY “How many rocks did {player3} collect?”
INPUT into rockCount3
IF rockCount3 < 0
    DISPLAY “Invalid input. Zero will be entered.”
    SET rockCount3 = 0
ENDIF

SET rockTotal = rockCount1 + rockCount2 + rockCount3
SET rockAverage = static_cast<double>(rockTotal) / NUM_PLAYERS

IF rockCount1 == rockCount2 AND rockCount1 == rockCount3
    DISPLAY “All players are tied”
ELSE IF rockCount1 == rockCount2
    IF rockCount1 > rockCount3
        DISPLAY “{player1} and {player2} are tied for first”
        DISPLAY “{player3} is in second”
    ELSE
        DISPLAY “{player3} is in first”
        DISPLAY “{player1} and {player2} are tied for second”
    ENDIF
ELSE IF rockCount2 == rockCount3
    IF rockCount2 > rockCount1
        DISPLAY “{player2} and {player3} are tied for first”
        DISPLAY “{player1} is in second”
    ELSE
        DISPLAY “{player1} is in first”
        DISPLAY “{player2} and {player3} are tied for second”
    ENDIF
ELSE IF rockCount1 == rockCount3
    IF rockCount1 > rockCount2
        DISPLAY “{player1} and {player3} are tied for first”
        DISPLAY “{player2} is in second”
    ELSE
        DISPLAY “{player2} is in first”
        DISPLAY “{player1} and {player3} are tied for second”
    ENDIF
ELSE IF (rockCount1 > rockCount2) AND (rockCount2 > rockCount3)
    DISPLAY “{player1} is in first”
    IF rockCount2 > rockCount3
        DISPLAY “{player2} is in second.”
        DISPLAY “{player3} is in third.”
    ELSE
        DISPLAY “{player3} is in second.”
        DISPLAY “{player2} is in third.”
    ENDIF
ELSE IF (rockCount2 > rockCount1) AND (rockCount2 > rockCount3)
    DISPLAY “{player2} is in first”
    IF rockCount1 > rockCount3
        DISPLAY “{player1} is in second.”
        DISPLAY “{player3} is in third.”
    ELSE
        DISPLAY “{player3} is in second.”
        DISPLAY “{player1} is in third.”
    ENDIF
ELSE IF (rockCount3 > rockCount1) AND (rockCount3 > rockCount1)
    DISPLAY “{player3} is in first”
    IF rockCount1 > rockCount2
        DISPLAY “{player1} is in second.”
        DISPLAY “{player2} is in third.”
    ELSE
        DISPLAY “{player2} is in second.”
        DISPLAY “{player1} is in third.”
    ENDIF
ENDIF

SET precision to 2 digits, fixed 
DISPLAY “The average number of rocks is {rockAverage}”

DISPLAY Exit message
```


