import requests
import json
import time

url = "https://nodes.get-scatter.com:443/v1/history/get_actions"

sum_action = 0;
else_transfer_action = 0
first = 0
offset = 100

else_transfer_action_list = {}
while True:
    response = requests.post(url, data = json.dumps({"account_name":"gm3denbwguge","pos":first,"offset":offset-1}))
    json_response = (response.json())["actions"]
    #print(len(json_response))
    # actual action numbers
    len_action = len(json_response)
    if(0 == len_action):
        break
    for x in json_response:
        #if "gm3denbwguge" != x["action_trace"]["receipt"]["receiver"]:
        if "transfer" != x["action_trace"]["act"]["name"] and "gm3denbwguge" !=  x["action_trace"]["receipt"]["receiver"]:
            print ("receipt_receiver = " + x["action_trace"]["receipt"]["receiver"])
            print (x["action_trace"]["act"]["name"] + " = " + x["action_trace"]["trx_id"])
            print ("***************")
            else_transfer_action_list[x["action_trace"]["act"]["name"]] = x["action_trace"]["trx_id"]
            #else_transfer_action_list.append(x["action_trace"]["act"]["name"])
            else_transfer_action = else_transfer_action+1
    first = first + len_action
    sum_action = sum_action + len_action

#else_transfer_action_list = list(set(else_transfer_action_list))
#else_transfer_action_list.sort()
#[(),()]
else_transfer_action_list = sorted(else_transfer_action_list.items(), key=lambda item:item[0])
#else_transfer_action_list = [item for item in else_transfer_action_list if else_transfer_action_list.count(item) == 1]
f = open("data1.md","wb")
for tup in else_transfer_action_list:
    if tup[0][-5:] == "_data":
        f.write(tup[0] + ' = ' + json.dumps(tup[1]))
    else:
        f.write(tup[0] + ' = ' + str(tup[1]))
    f.write('\n')
f.close()

print ("else_transfer_action = " + str(else_transfer_action))
print ("sum_action = " + str(sum_action))