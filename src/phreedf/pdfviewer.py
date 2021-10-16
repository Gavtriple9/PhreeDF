import tkinter as tk
from config import *

class PDFViewer():
    """PDF Viewer Section of App"""
    def __init__(self, master=None, width=100, height=80, **kw):
        self.main_frame = tk.Frame(master, width= width, height= height, bg=BACKGROUND_COLOR)
        self.main_frame.place(relheight=0.1, relwidth=1)
    