from cs50 import get_float

# condição para o input do usuario
while True:
    dollar = get_float("Change owed: ")
    if dollar >= 0:
        break
    
# faz o arredondamento    
cents = round(dollar * 100)
# variavel para contar a qntd de moeda
count_coins = 0

# condições para a conta ser feita
while cents >= 25:
    cents -= 25
    count_coins += 1
    
while cents >= 10:
    cents -= 10
    count_coins += 1
    
while cents >= 5:
    cents -= 5
    count_coins += 1
    
while cents >= 1:
    cents -= 1
    count_coins += 1
    
print(f"You'll need at least {count_coins} coins")