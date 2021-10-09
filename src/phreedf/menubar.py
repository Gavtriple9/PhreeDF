from tkinter import *
from tkinter.ttk import *

# from containers

class Menubar:
    def __init__(self, container):
        self.fileFrame = Frame(container)
        print(self.fileFrame.configure().keys())
        self.fileFrame.pack()
        self.homeFrame = Frame(container)
        self.viewFrame = Frame(container)
        self.commentFrame = Frame(container)
        self.protectFrame = Frame(container)
        self.formFrame = Frame(container)
        self.organizeFrame = Frame(container)
        self.shareFrame = Frame(container)
        self.reviewFrame = Frame(container)
        self.helpFrame = Frame(container)
        self.formatFrame = Frame(container)
        
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