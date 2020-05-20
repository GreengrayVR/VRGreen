def class_format(class_name):
    class_name = class_name.upper().replace('.', '_').replace(',', '_').replace('<', '_').replace('>', '_')

    class_name = class_name.split('//')[0]

    if class_name.__contains__(':'):
        inheritance = class_name.split(':')[1].split(' ')[1]
        class_name = class_name.split(':')[0]
        class_name = class_name.split(' ')[len(class_name.split(' ')) - 2]

        class_name = class_name + '_' + inheritance
    else:
        class_name = class_name.replace(' ', '_')

    return class_name

def function_format(text, class_name):
    parameters = ''

    text = text.replace('.', '').replace('\t', '').replace('[', '0').replace(']', '1')

    if text.__contains__('()'):
        return class_format(class_name) + '_' + text[:-6].replace(' ', '_').upper()
    elif text.__contains__(', '):
        params = text.split(',')
        params[0] = params[0].split('(')[1] # make first param pretty

        for i in range(len(params)):
            params[i] = params[i].replace('<', '_').replace('>', '_')

        for i in range(len(params)):
            #print(params[i])
            if i != 0:
                try:
                    temp = params[i].split(' ')[1] + ' ' + params[i].split(' ')[2]
                    params[i] = temp.upper().replace(' ', '_')
                except:
                    pass
            else:
                params[i] = params[i].upper().replace(' ', '_')

        for i in range(len(params)):
            parameters += params[i] + '____'

        parameters = parameters[:-5].replace(' ', '_')
    else:
        parameters = text.split('(')[1].split(')')[0].replace(' ', '_').upper()

    return (class_format(class_name) + '_' + text.split('(')[0].upper().replace(' ', '_') + '____' + parameters).replace('[', '0').replace(']', '1').replace('*', 'PTR')


f = open('T:\\IL2CPP\\VRGreen\\VRGreen\\dump2.cs', "r") #  file to open

f2 = open('AllOffsets.h', 'w') # file to write to


f2.write('#pragma once\n\n') # no need to say thanks ;)

class_name = ''
previous = ''

rva = ''

i = 0


for line in f:
    i += 1
    #print(i)

    line = line.rsplit('\n')[0]
    
    if line.__contains__('xxxx'):
        continue

    if line.__contains__('class '):
        class_name = line
        
    if not line.__contains__('class') and not line.__contains__('// 0x') and not line.__contains__('<') and not line.__contains__('xxxx') and not line.__contains__('get;') and not line.__contains__('set;') and line.__contains__('public') or line.__contains__('private'):
        if previous.__contains__('RVA'):
            rva = previous.split(' ')[2]
        else:
            rva = 'EMPTY_RVA'
        

        if not line.__contains__('// 0x') and not line.__contains__('<') and not line.__contains__('set') and not line.__contains__('get;') and not line.__contains__('struct') and not line.__contains__('enum') and not line.__contains__('[,]') and not line.__contains__('[,,]') and not line.__contains__('interface') and not line.__contains__('class'):
            f2.write(f'// {line} ( {class_name} )\n')
            f2.write(f'#define {function_format(line, class_name)} {rva} // line: {i}\n\n')
            
    previous = line



f.close()
f2.close()