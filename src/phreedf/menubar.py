import tkinter as tk
from tkinter import ttk

import os
from PIL import ImageTk, Image

class Menubar:
    def __init__(self, container):

        self.fileFrame = ttk.Frame(container)
        self.homeFrame = ttk.Frame(container, height=200, width=100)
        self.viewFrame = ttk.Frame(container)
        self.commentFrame = ttk.Frame(container)
        self.protectFrame = ttk.Frame(container)
        self.formFrame = ttk.Frame(container)
        self.organizeFrame = ttk.Frame(container)
        self.shareFrame = ttk.Frame(container)
        self.reviewFrame = ttk.Frame(container)
        self.helpFrame = ttk.Frame(container)
        self.formatFrame = ttk.Frame(container)
        
        container.add(self.fileFrame, text='File')
        container.add(self.homeFrame, text='Home')
        container.add(self.viewFrame, text='View')
        container.add(self.commentFrame, text='Comment')
        container.add(self.protectFrame, text='Protect')
        container.add(self.formFrame, text='Form')
        container.add(self.organizeFrame, text='Organize')
        container.add(self.shareFrame, text='Share')
        container.add(self.reviewFrame, text='Review')
        container.add(self.helpFrame, text='Help')
        container.add(self.formatFrame, text='Format')