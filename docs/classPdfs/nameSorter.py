import os

for pdf in os.listdir(os.getcwd()):
    if "__in" in pdf:
        os.system("rm " + pdf)
    elif "__co" in pdf:
        new_name = pdf[:pdf.index("_")] + ".pdf"
        os.system("mv " + pdf + " " + new_name)
