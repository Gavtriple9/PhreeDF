import tkinter as tk
from tkinter import ttk

import os
from PIL import ImageTk, Image

from config import *

class Menubar:
    def __init__(self, container):

        self.file_frame = tk.Frame(container)
        self.home_frame = ttk.Frame(container, height=200, width=100)
        self.view_frame = ttk.Frame(container)
        self.comment_frame = ttk.Frame(container)
        self.protect_frame = ttk.Frame(container)
        self.form_frame = ttk.Frame(container)
        self.organize_frame = ttk.Frame(container)
        self.share_frame = ttk.Frame(container)
        self.review_frame = ttk.Frame(container)
        self.help_frame = ttk.Frame(container)
        self.format_frame = ttk.Frame(container)
        
        container.add(self.file_frame, text='File')
        container.add(self.home_frame, text='Home')
        container.add(self.view_frame, text='View')
        container.add(self.comment_frame, text='Comment')
        container.add(self.protect_frame, text='Protect')
        container.add(self.form_frame, text='Form')
        container.add(self.organize_frame, text='Organize')
        container.add(self.share_frame, text='Share')
        container.add(self.review_frame, text='Review')
        container.add(self.help_frame, text='Help')
        container.add(self.format_frame, text='Format')