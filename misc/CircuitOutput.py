# Online Python compiler (interpreter) to run Python online.
# Write Python 3 code in this online editor and run it.
def AND (a, b):
    if a == 1 and b == 1:
        return 1
    else:
        return 0
        
def NAND (a, b):
    if a == 1 and b == 1:
        return 0
    else:
        return 1
def OR(a, b):
    if a == 1 or b ==1:
        return 1
    else:
        return 0
def NOT(a):
    return int(not a)
def NOR(a, b):
    if(a == 0) and (b == 0):
        return 1
    elif(a == 0) and (b == 1):
        return 0
    elif(a == 1) and (b == 0):
        return 0
    elif(a == 1) and (b == 1):
        return 0
def XOR (a, b):
    if a != b:
        return 1
    else:
        return 0
def XNOR(a,b):
    if(a == b):
        return 1
    else:
        return 0
def NAND3(a,b,c):
    return int(NOT(a) + NOT(b) + NOT(c))
def NOR3(a,b,c):
    return int(NOT(OR(a, OR(b,c))))

n = int(input("enter N "))
e = int(input("enter number of gates "))
p = int(input("enter number of primary inputs "))
input_list = []
gates = []
output_list = []
for i in range(0, e):
    identifier = input("enter identifier ")
    type_gate = input("enter type ")
    gates.append(type_gate)
    if type_gate.lower() == "NOT".lower():
        no_inputs = 1
    else:
        no_inputs = int(type_gate[-1])
    l = []
    for j in range(0, no_inputs):
        i_net = int(input("enter input nets "))
        l.append(i_net)
    input_list.append(l)
    output = int(input("enter output gate"))
    output_list.append(output)

dct = dict()

for i in range(0, p):
    key = int(input("enter primary input net "))
    value = int(input("enter value "))
    dct[key] = value

for i in range(0, len(gates)):
    if gates[i] == "NOT":
        dct[output_list[i]] = NOT(dct[input_list[i][0]])
    elif gates[i] == "AND2":
        dct[output_list[i]] = AND(dct[input_list[i][0]], dct[input_list[i][1]])
    elif gates[i] == "OR2":
        dct[output_list[i]] = OR(dct[input_list[i][0]], dct[input_list[i][1]])
    elif gates[i] == "NAND2":
        dct[output_list[i]] = NAND(dct[input_list[i][0]], dct[input_list[i][1]])
    elif gates[i] == "NOR2":
        dct[output_list[i]] = NOR(dct[input_list[i][0]], dct[input_list[i][1]])
    elif gates[i] == "XOR2":
        dct[output_list[i]] = XOR(dct[input_list[i][0]], dct[input_list[i][1]])
    elif gates[i] == "XNOR2":
        dct[output_list[i]] = XNOR(dct[input_list[i][0]], dct[input_list[i][1]])
    elif gates[i] == "NAND3":
        dct[output_list[i]] = NAND3(dct[input_list[i][0]], dct[input_list[i][1]], dct[input_list[i][2]])
    elif gates[i] == "NOR3":
        dct[output_list[i]] = NOR3(dct[input_list[i][0]], dct[input_list[i][1]], dct[input_list[i][2]])

for key, value in dct.items():
    print("{}  {}".format(key, value))
        
