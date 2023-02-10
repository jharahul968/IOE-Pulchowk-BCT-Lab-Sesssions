import os

def show_items_in_(path):
  for entry in os.listdir(path):
    print(f'{entry}', end="	")
show_items_in_(".")