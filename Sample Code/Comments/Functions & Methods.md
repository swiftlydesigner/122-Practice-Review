#Comments

## Function and Method Comment Blocks

`
/// <#DESCRIPTION OF FUNCTION#>
///
/// - Precondition: <#WHAT DO WE NEED TO CALL *BEFORE* CALLING?#>
/// - Postcondition: <#WHAT DO WE NEED TO KNOW *AFTER* CALLING?#>
/// - Warning: <#IS THERE SOMETHING THAT COULD GO WRONG? CRASH? PURPOSEFUL EXIT? POINTER IS POSSIBLY NULL?#>
/// - Parameter <#PARAM NAME#>: <#WHY DO WE USE THIS PARAM?#>
/// - Parameter <#PARAM NAME#>: <#WHY DO WE USE THIS PARAM?#>
/// - Parameter <#PARAM NAME#>: <#WHY DO WE USE THIS PARAM?#>
/// - Parameter <#PARAM NAME#>: <#WHY DO WE USE THIS PARAM?#>
/// - Returns: <#WHAT DOES IT RETURN?#>
/// - Seealso: [<#NAME OF THE COMPANY WE GOT IT FROM#>, "<#NAME OF THE SOURCE WE ARE USING#>"] (<#URL TO SEEALSO#>)
/// - Date: <#UPDATE DATE#>
///
/// - Version: <#1.0#>
`

### Proper Formats
#### Alternative Block Style
These should be attacted to all functions and methods you create In this class. If you do not like the `///` format, then use `/**` with a preceding * on each line; term with `*/` There are other styles of documentation, feel free to look into those as well.

#### Description
The description should be breif, yet descriptive. If you cannot tell what is going on from the description, rewrite it.

#### Pre- and Post- Conditions
- Pre- and Post- conditions are likely to be used in a lot of funcs/methods.
- Preconditions are one that must be met prior to running this code.
- Post conditions are ones that will be true after the func is called. 

#### Warnings [Optional]
Warnings are for when the program could crash as a result of misuse or if an unintented sideffect occurs are specfic times.

#### Paramters (or Param or Paramter)
Paramters are very important. Be sure to use the format above. We need to know it is a parameter, what the name is, and what it is used for. Many people comment just what the positional argument is, but we need to label it. Of course, only add these if there is a paramter.

#### Returns
Returns tag is also very importnat. We need to know what is being returned. Althought importnant, it can be very short in the description.

#### Seealso [Optional]
Seealso tag is used when we need to references another site use the format above) or when we need to reference another function. For example, if we have a recursive function, we need to create a helper function. We would then want to use a seealso tag.

#### Date
Date tag is updated everytime you update the function. You can add a creation tag if you would like, but a single date tag is good enough.

#### Version [Optional]
Version tag is self-explanatory. It can be numbers or letters or a mix. Optional.

#### Others
There are other tags that you can add. You will need to look these up on your own time. Of course, these will be fully optional.
