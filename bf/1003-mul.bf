# BrainF*ck Script to multiply two numbers
# Result has to be less than 10 (a single digit number)
# Given example 42: 4 will be in block #1, 2 will be in block #2
# Block 0 will store the result
# Block 1 will hold the value to multiply
# Block 2 will hold the amount of times to multiply

# Initialize block 0 with value 0
[>++++++++++<-] # Set block 0 to 0

# Read input into block 1 and 2
>,------------------------------------------------ # Read into block #1
>,------------------------------------------------ # Read into block #2

[   # Start of multiplication loop
    # Copy block 1 into block 3 and 0, then copy block 3 back to block 1
    <[>>+<<<+>-]>>[<<+>>-]

    # Move block 2 to block 3 and decrease
    <[-] # Done with one iteration

    # Clear block 3 for the next iteration
    >>[-]<<<
]

# Move to block 0 and increase by ASCII '0' (DEC 48)
<<++++++++++++++++++++++++++++++++++++++++++++++++.

# Print the result
.
