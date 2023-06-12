with open('latex.log','r',encoding='utf-8') as f:
    rows_set=set(f.readlines())
    print('共{}关键行'.format(len(rows_set)))