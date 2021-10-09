from tkinter import *
from tkinter.ttk import *

import os
from menubar import *

class PhreeDF():
    

    def __init__(self, root):
        
        pathToIcon = os.path.join(os.path.split(os.path.abspath(__file__))[0], '../icon/icon.png')
        img = PhotoImage(file=pathToIcon)
        root.tk.call('wm', 'iconphoto', root._w, img)

        root.title("PhreeDF")
        root.iconbitmap(pathToIcon)

        PDFNotebook = Notebook(root)
        PDFNotebook.pack()

        self.menuBar = Menubar(PDFNotebook)
        root.bind('<Escape>', close)

    
def close(event):
    root.destroy()
    

root = Tk()


PhreeDF(root)
root.mainloop()