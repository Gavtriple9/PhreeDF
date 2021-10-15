import tkinter as tk
from tkinter import ttk
from tkinter import filedialog
from PIL import ImageTk, Image
from tkPDFViewer import tkPDFViewer as pdf
import PyPDF2 

import os
from menubar import Menubar

HEIGHT = 1080
WIDTH = 1920

class PhreeDFApp():
    
    
    def __init__(self, root):
        pathToAppIcon = os.path.join(os.path.split(os.path.abspath(__file__))[0], '../icon/icon.png')
        pathToPDF = os.path.join(os.path.split(os.path.abspath(__file__))[0], '../data/pdf-test-2.pdf')
        img = Image.open(pathToAppIcon)
        icon = ImageTk.PhotoImage(img)

        root.tk.call('wm', 'iconphoto', root._w, icon)
        root.geometry( str(HEIGHT) + "x" + str(WIDTH) )

        root.title("PhreeDF")

        ribbon = ttk.Notebook(root)
        ribbon.place(relheight=1, relwidth=1)
        
        self.menuBar = Menubar(ribbon)
        ribbon.select(self.menuBar.homeFrame)

        v1 = pdf.ShowPdf()
        v2 = v1.pdf_view(self.menuBar.homeFrame,
                 pdf_location = pathToPDF, 
                 width = 100, height = HEIGHT)
        print(v2.config)
        v2.pack()

        my_menu= tk.Menu(root)
        root.config(menu=my_menu)

        file_menu=tk.Menu(my_menu,tearoff=False)
        my_menu.add_cascade(label="File",menu= file_menu)
        file_menu.add_command(label="Open",command=self.open_pdf)
        file_menu.add_command(label="Close",command=self.close)
    

        root.bind('<Escape>', self.close)
    
    def clear_text(self):
        self.text.delete(1.0, tk.END)
    
    def open_pdf(self):
        pass
        # file = filedialog.askopenfilename(title="Select a PDF", filetype=(("PDF    Files","*.pdf"),("All Files","*.*")))
        # if file:
        #     #Open the PDF File
        #     pdf_file= PyPDF2.PdfFileReader(file)
        #     #Select a Page to read
        #     page= pdf_file.getPage(0)
        #     #Get the content of the Page
        #     content=page.extractText()
        #     print(content)
        #     #Add the content to TextBox
        #     self.text.insert(1.0,content)

    def close(self,event=-1):
        root.destroy()
        print("Goodbye")


    
if __name__ == "__main__":
    root = tk.Tk()
    mainApp = PhreeDFApp(root)
    root.mainloop()