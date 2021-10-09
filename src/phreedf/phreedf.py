from tkinter import *
from tkinter.ttk import *

import os
from menubar import *

class PhreeDF():

    def __init__(self, root):
        
        # abs_path_of_executable_file = os.path.split(os.path.abspath(__file__))
        # print(abs_path_of_executable_file)
        # path_to_png = os.path.join(abs_path_of_executable_file[0], 'support/icon/icon.png')
        # print(path_to_png)

        root.title("PhreeDF")
        # root.iconbitmap(path_to_png)

        PDFNotebook = Notebook(root)
        PDFNotebook.pack()

        self.menuBar = Menubar(PDFNotebook)

        

   
 

root = Tk()
PhreeDF(root)
root.mainloop()