import os
import math
from PIL import Image
from PyPDF2 import PdfFileReader

def extract_information(pdf_path):
    with open(pdf_path, 'rb') as f:
        pdf = PdfFileReader(f)
        # pdf.decrypt("")
        information = pdf.getDocumentInfo()
        number_of_pages = pdf.getNumPages()

    txt = f"""
    Information about {pdf_path}: 

    Author: {information.author}
    Creator: {information.creator}
    Producer: {information.producer}
    Subject: {information.subject}
    Title: {information.title}
    Number of pages: {number_of_pages}
    """
    
    print(txt)
    return information

if __name__ == '__main__':
    path = os.path.join(os.path.split(os.path.abspath(__file__))[0], '../data/pdf-test-2.pdf')
    extract_information(path)