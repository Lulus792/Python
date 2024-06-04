from util import reverse_list

class Tupel:
    
    def __init__(this, val1:any, val2:any):
        this.first:any = val1
        this.second:any = val2
        this.current = None

    def __iter__(this):
        return this

    def __next__(this):
        if this.current == None:
            this.current = 1 
            return this.first
        elif this.current == 1:
            this.current = 2
            return this.second
        raise StopIteration

class binary:

    def __init__(this, value:int, binary:list[int]):
        def to_binary(this):
            def remove_front_zeros(arr:list[int]) -> list[int]:
                while arr[len(arr) - 1] == 0:
                    arr.pop()
                return arr

            while this.value > 0:
                rest:int = this.value % 2; this.value //= 2 
                this.binary.append(rest)        

            this.binary = reverse_list(remove_front_zeros(this.binary))

        this.value:int = value 
        this.binary:list[int] = binary 

        if this.binary == []:
            to_binary(this)

    def __str__(this):
        return f'{this.binary}'


def convert_to_binary(num:int) -> binary:
    return binary(num, []) 

def XOR(num1:any, num2:any) -> Tupel:
    return Tupel(num1, num2)

def XOR_BIN(num1:binary, num2:binary) -> Tupel:
    def value_to_change(num1:binary, num2:binary) -> Tupel:
        for val1, val2 in zip(num1.binary, num2.binary):
            if val1 == val2:
                val1 == 0
            else:
                val1 == 1
        return Tupel(num1, num2)
    
    num1, num2 = value_to_change(num1, num2)
    num1, num2 = value_to_change(num2, num1)
    num1, num2 = value_to_change(num1, num2)

    return Tupel(num1, num2)
