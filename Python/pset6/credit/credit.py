from cs50 import get_string
from math import floor

AE1 = "34"
AE2 = "37"
MC1 = "51"
MC2 = "52"
MC3 = "53"
MC4 = "54"
MC5 = "55"
Visa = "4"
brand = "INVALID"

# get and clean the input from the user
card = get_string("Card n*: ")
card = card.strip()
count = len(card)

# compare first 2 digits to the saved codes and assign a brand
if (count == 13):
    if (card[:1] == Visa):
        brand = "VISA"

elif (count == 15):
    if (card[:2] == AE1 or card[:2] == AE2):
        brand = "AMEX"

elif (count == 16):
    if (card[:2] == MC1 or card[:2] == MC2 or card[:2] == MC3 or card[:2] == MC4 or card[:2] == MC5):
        brand = "MASTERCARD"

    elif (card[:1] == Visa):
        brand = "VISA"

# if the number of digits is correct it now checks that luhn's Algorithm is respected, otherwise returns INVALID
if (brand != "INVALID"):
    card = int(card)
    last = 0
    tempx = 0
    secToLast = 0

    # it picks odd and even numbers starting from the end and sums them
    while (card > 0):
        last += card % 10

        # eliminates last digit so we can access the first even number from the end
        card /= 10
        card = floor(card)

        tempx = (card % 10) * 2

        # if the even number * 2 is 10 or bigger it takes the single digits and adds them the rest of the odds
        if (tempx >= 10):
            secToLast += tempx % 10
            tempx /= 10
            secToLast += floor(tempx)

        # if the even number * 2 is 9 or less it just adds it to the others
        else:
            secToLast += tempx

        card /= 10
        card = floor(card)

    # if it validates the Algorithm prints the brand
    if ((last + secToLast) % 10 == 0):
        print(brand)

    else:
        print("INVALID")

# again it prints invalid if the digits number was not correct in the first place
else:
    print(brand)