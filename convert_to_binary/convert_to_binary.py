from binary import binary
from util import reverse_list

def remove_front_zeros(arr:list[any]) -> list[any]:
   while arr[len(arr) - 1] == 0:
      arr.pop()
   return arr

def convert_to_binary(num:int) -> binary:
   ret:binary = binary() 
   while num > 0:
      rest:int = num % 2; num = num // 2 
      ret.value.append(rest)

   ret.value = remove_front_zeros(reverse_list(ret.value))
   return ret 
