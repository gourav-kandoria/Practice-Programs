#!/usr/bin/python3
y = 10
def fun() :
  z = 10
  print(z)
  def fun1():
    global y
    nonlocal z
    z = 3
    y = 3
    print(z)
  fun1()
  print(z)
  print(y)
