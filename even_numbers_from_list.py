# Python program to print even Numbers in a List
  
def return_even_numbers_from_list(numbers_list):
    """
    Returns even numbers from a list of numbers
    """

    even_numbers = [num for num in numbers_list if num % 2 == 0]
    return even_numbers

list_of_nums = [100, 35, 4, 25, 88, 73]

# returns [100, 4, 88]
print(return_even_numbers_from_list(list_of_nums))