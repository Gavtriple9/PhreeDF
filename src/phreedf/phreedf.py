# library imports
import os
import tkinter as tk
from tkinter import ttk
from tkinter import filedialog
from PIL import ImageTk, Image
import PyPDF2 

# locally defined imports
from config import *
from pdfviewer import PDFViewer
from menubar import Menubar


class PhreeDFApp():
    """The main app class"""
    
    def __init__(self, root):
        # set main icon of app
        path_to_app_icon = os.path.join(os.path.split(os.path.abspath(__file__))[0], '../icon/icon.png')
        img = Image.open(path_to_app_icon)
        icon = ImageTk.PhotoImage(img)
        root.tk.call('wm', 'iconphoto', root._w, icon)
        root.geometry( '%dx%d' % (HEIGHT,WIDTH) )
        root.title("PhreeDF")

        # set paths of pdf
        path_to_pdf = os.path.join(os.path.split(os.path.abspath(__file__))[0], '../data/pdf-test-2.pdf')
        pdf_data = PyPDF2.PdfFileReader(path_to_pdf)

        print(pdf_data.documentInfo)

        self.top_ribbon = ttk.Notebook(root)
        self.top_ribbon.pack(fill=tk.X)
        
        self.menubar = Menubar(self.top_ribbon)
        self.top_ribbon.select(self.menubar.home_frame)

        # self.pdf_viewer = PDFViewer(root)

        root.bind('<Escape>', self.close_app)


    def clear_text(self):
        self.text.delete(1.0, tk.END)
    
    def open_pdf(self):
        file = filedialog.askopenfilename(title="Select a PDF", filetype=(("PDF    Files","*.pdf"),("All Files","*.*")))
        if file:
            #Open the PDF File
            pdf_file= PyPDF2.PdfFileReader(file)
            #Select a Page to read
            page= pdf_file.getPage(0)
            #Get the content of the Page
            content=page.extractText()
            print(content)
            #Add the content to TextBox
            self.text.insert(1.0,content)

    def close_app(self,event=-1):
        root.destroy()
        print("Goodbye")


    
if __name__ == "__main__":
    root = tk.Tk()
    main_app = PhreeDFApp(root)
    root.mainloop()
    

    """
    code to add a menubar
    my_menu= tk.Menu(root)
    root.config(menu=my_menu)

    file_menu=tk.Menu(my_menu,tearoff=False)
    my_menu.add_cascade(label="File",menu= file_menu)
    file_menu.add_command(label="Open",command=self.open_pdf)
    file_menu.add_command(label="Close",command=self.close_app)
    """