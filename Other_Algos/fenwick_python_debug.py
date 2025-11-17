# for index in range(1, 102):
#     # print(index)
#     for i in range(10):
#         print(index, end=' -> ')
#         index = index + (index & -index)
#     print()
# print("-----")
# for index in range(100, 1, -1):
#     # print(index)
for index in range(16, 0, -1):
    for i in range(10):
        print(index, end=' -> ')
        index = index - (index & -index)
    print()
    