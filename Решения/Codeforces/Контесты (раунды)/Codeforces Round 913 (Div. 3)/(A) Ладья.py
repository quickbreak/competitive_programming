for _ in range(int(input())):
   s = input()
   a, b = s[0], s[1]
   for i in range(1, 8+1):
      if(str(i)!=b):
         print(f'{a}{i}')
   for i in 'abcdefgh':
      if(i!=a):
         print(f'{i}{b}')