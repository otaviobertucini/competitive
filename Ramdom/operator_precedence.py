def main():
    print("Type the proposition: ")
    txt = str(input())
    txt = txt.replace(" ", "")
    complete(txt)

def complete(txt):
    txt = negative(txt)
    txt = connectives(txt, "&")
    txt = connectives(txt, "|")
    txt = connectives(txt, "-")    
    print(txt)

def negative(txt):
    i = 0
    txt_len = len(txt)
    while i < txt_len:
        if txt[i] == "~":
            txt = insert_par(txt, i, negative_end(txt, i))
            i += 1
        i += 1
        txt_len = len(txt)
    return txt

def connectives(txt, char):
    i = len(txt) - 1
    while i > -1:
        if(txt[i] == char):
            txt = insert_par(txt, find_end(txt, i, -1), find_end(txt, i, 1)+1)
        i -= 1
    return txt

def negative_end(txt, i):
    i += 1
    while True:
        if txt[i].isalpha() or i == len(txt) - 1:
            return i + 1
        i += 1

def find_end(txt, i, sum):
    par_queue = []
    close = "("
    open = ")"
    if(sum == 1):
        close = ")"
        open = "("
    while i > 0 and i < len(txt) - 1:
        i += sum
        if(txt[i] == open):
            par_queue.append(open)
        elif(txt[i] == close):
            par_queue.pop()
        if txt[i] in ["&", "|", "-"] and len(par_queue) == 0:
            return i + sum*-1
    return i

def insert_par(txt, a, b):
    return txt[:a] + "(" + txt[a:b] + ")" + txt[b:]

main()
