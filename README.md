# Contrast-Ratio-Checker
A small program written in C, to take 2 colours in RGB Values and calculate their contrast ratio

## Usage
Program takes 6 arguments - the first 3 are the RGB values of a first colour, the second 3 are the RGB values of a second colour. The program outputs the contrast ratio and whether it meets WCAG 2.0 guidelines.

    $ ./contrast 255 255 255 0 0 0

## Development
Despite there being a host of tools online to check this, I plan on using this logic in a number of projects, and thus wanted to prototype the logic to either create an API or adapt to other projects manually.

## Future plans

 - Accept other colour inputs
 -- Hex
 -- HSL
 -- HTML5 Names

## Contributions
As the software is part of a portfolio that I will be improving I am not looking for contribution, however if the current version of the software is of use to you, then the software is available under GPL, all I ask is for ackonowledgement.

## License
[GNU GPLv3](https://choosealicense.com/licenses/gpl-3.0/)
