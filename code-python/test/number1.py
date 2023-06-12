cnt=1
while cnt<=3:
    name=input()
    password=input()
    if name=='Kate' and password=='666666':
        print("登录成功！")
        break
    else:
        cnt+=1
        if cnt>3:
            print("3次用户名或者密码均有误！退出程序。")
        