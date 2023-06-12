import re

regex = r"<h3 class=\"tit\">(\n.*\n.*\n.*\n.*\n.*\n.*\n.*\n.*\n.*\n.*\n.*\n.*\n.*\n.*\n.*\n.*\n.*\n.*\n.*\n.*\n.*\n.*\n.*\n.*)\n *.*竞赛详情</a>"

regex = r"<h3 class=\"tit\">((\n.*){5,25}).*竞赛详情<\/a>"

regex1 = r"title.*>(.*)<\/a>\n.*\n.*主办方<\/span>(.*)<\/p>\n.*竞赛级别<\/span>(.*)<.*>\n.*报名时间<\/span>(.*)<\/p>\n.*比赛时间<\/span>(\n+.*)<\/p>"

def get_info(path):

    res_in=[]
    res_out=[]
    text=''
    with open(path,'r') as f:
        text=f.read()

    matches = re.finditer(regex, text, re.MULTILINE)

    for matchNum,match in enumerate(matches,start=1):

        #print ("Match {matchNum} was found at {start}-{end}: {match}".format(matchNum = matchNum, start = match.start(), end = match.end(), match = match.group()))
        matches_iter = re.findall(regex1, match.group(), re.MULTILINE)
        for i in matches_iter:
            for i_iter in i:
                x=re.sub('\s+','',i_iter).strip()
                res_in.append(x)
            res_out.append(res_in)
            res_in=[]

    print(res_out)
    return res_out

