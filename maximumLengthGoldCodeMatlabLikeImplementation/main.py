from scripis.Gold import Gold

if __name__ == '__main__':
    # Gold sequence
    init = [0, 0, 0, 0, 0, 0, 0, 1]

    poly1 = [8, 6, 5, 3, 0]
    poly2 = [8, 6, 5, 2, 0]
    frame_length = 2 ** len(init) - 1  # Maximum length before the code repeats itself.

    gold = Gold(poly1, init, poly2, init, matlab=True)
    gold_sequence = gold.step()

    print(gold_sequence)
    print(type(gold_sequence))
    print(len(gold_sequence))

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
