from cs50 import get_int

# condição para gerar a pirâmide
while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break
    
# se a condição for atendida, irá começar a aninhar esses loop's
for row in range(0, height, 1):
    for column in range(0, height, 1):
        if (row + column < height - 1):
            print(" ", end="")
        else:
            print("#", end="")
    
    # espaço entra as pirâmides
    print("  ", end="")
    
    # segunda pirâmide
    for column in range(0, height, 1):
        if (column <= row):    
            print("#", end="")
    print("")    
    