# Norwegian county numbers (kommunenummer)
This project contains a library for computations on norwegian county numbers in many programming languages. The library works exactly the same in all implementations:

 * Java
 * C
 * C++
 * JavaScript
 * C#
 * PHP
 * Python
 * Visual Basic

Norwegian county numbers are called "kommunenummer" in norwegian.

The library has been made with [progsbase](https://www.progsbase.com), a tool for creating rot-resistant programs that are translatable to many programming languages.

The library can also be browsed and tested on the [progsbase repository's kommunenummer page](https://repo.progsbase.com/repoviewer/no.inductive.libraries/kommunenummer/0.1.1).

![progsbase logo](/docs/images/progsbase-logo.png)

For more information about progsbase, check out: [progsbase.com](https://www.progsbase.com).

## Usage

The library has the same interface in all programming languages.

### Validate
`boolean erGyldigKommunenummer(char [] kommunenummer)`

The function takes a string as input containing the county number (kommunenummer) and returns true if valid and existing and false if not.

### Get county name from number
`char [] hentKommunenavnFraNummer(char [] kommunenummer, Success success)`

The function takes a string as input, containing a norwegian county number (kommunenummer) and a structure Success.

The output is a string with the county name. Also, if the call fails, success.success is false and a human readable reason is placed in success.feilmelding.
