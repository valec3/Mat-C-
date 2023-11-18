from itertools import combinations

def count_triplets(lista):
    count = 0
    triplets = combinations(lista, 3)

    for triplet in triplets:
        if sum(triplet) == 5000:
            count += 1

    return count


if __name__ == "__main__":
    n = int(input())
    numbers = [int(input()) for _ in range(n)]

    resultado = count_triplets(numbers)
    print(resultado)