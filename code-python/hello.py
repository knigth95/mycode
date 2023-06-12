from PIL import Image

char_set = '''$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,\"^`'. '''


im = Image.open('qq.png')
im = im.resize((80, 50), Image.ANTIALIAS)
im = im.convert('L')    # 转为黑白图, 每个像素都一个灰度值,从0到255, 0是黑色, 255是白色
im.save('t.jpeg')


def get_char(gray):
    if gray >= 240:
        return ' '
    else:
        return char_set[int(gray/((256.0 + 1)/len(char_set)))]

text = ''
for i in range(im.height):
    for j in range(im.width):
        gray = im.getpixel((j, i))      # 返回值可能是一个int, 也可能是一个三元组
        if isinstance(gray, tuple):
            gray = int(0.2126 * gray[0] + 0.7152 * gray[1] + 0.0722 * gray[2])

        text += get_char(gray)
    text += '\n'

with open('pic.txt', 'w')as f:
    f.write(text)