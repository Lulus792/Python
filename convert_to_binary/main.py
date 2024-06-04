from binary import binary, convert_to_binary, XOR_BIN

def main():
    num1, num2 = XOR_BIN(binary(12, []), binary(14, []))
    print(num1)
    print(num2) 

if __name__ == '__main__':
    main()