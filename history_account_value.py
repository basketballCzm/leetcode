# -*- coding: utf-8 -*-  
import requests
import json
import time

url = "https://nodes.get-scatter.com:443/v1/history/get_actions"

def get_value(str):
	return float(str.split(" ")[0])

sum_from  = 0.0
sum_to = 0.0
sum_sum = 0.0
first = 0
offset = 100
sum_action = 0

transfer_list = {}

while True:
    response = requests.post(url, data = json.dumps({"account_name":"gm3denbwguge","pos":first,"offset":offset-1}))
    json_response = (response.json())["actions"]
    print(len(json_response))
    # actual action numbers
    len_action = len(json_response)
    if(0 == len_action):
    	break
    for x in json_response:
    	if "gm3denbwguge" != x["action_trace"]["receipt"]["receiver"]:
    		continue
    	# transaction 9163a1b218134050a885406ae512e445825b19965456e07b7c91623d45cae782
    	if "transfer" == x["action_trace"]["act"]["name"] and dict == type(x["action_trace"]["act"]["data"]):
    		if "gm3denbwguge" == x["action_trace"]["act"]["data"]["from"] and "EOS" == x["action_trace"]["act"]["data"]["quantity"].split(" ")[1]:
    			sum_sum = sum_sum - get_value(x["action_trace"]["act"]["data"]["quantity"])
    			sum_from = sum_from + get_value(x["action_trace"]["act"]["data"]["quantity"]) 
    			transfer_list[x["action_trace"]["trx_id"]+"_from"] = x["action_trace"]["act"]["data"]["quantity"]
    			#print(get_value(x["action_trace"]["act"]["data"]["quantity"]))
    		if "gm3denbwguge" == x["action_trace"]["act"]["data"]["to"] and "EOS" == x["action_trace"]["act"]["data"]["quantity"].split(" ")[1]:
    			sum_sum = sum_sum + get_value(x["action_trace"]["act"]["data"]["quantity"])
    			sum_to = sum_to + get_value(x["action_trace"]["act"]["data"]["quantity"])
    			transfer_list[x["action_trace"]["trx_id"]+"_to"] = x["action_trace"]["act"]["data"]["quantity"]
    			#print(get_value(x["action_trace"]["act"]["data"]["quantity"]))
    first = first + len_action
    sum_action = sum_action + len_action

transfer_list = sorted(transfer_list.items(), key=lambda item:item[0])
f = open("data.md","wb")
for tup in transfer_list:
    if tup[0][-5:] == "_data":
        f.write(tup[0] + ' = ' + json.dumps(tup[1]))
    else:
        f.write(tup[0] + ' = ' + str(tup[1]))
    f.write('\n')
f.close()

print ('sum_from = '+ str(sum_from))
print ('sum_to = '+ str(sum_to))
print ('sum_to-sum_from = '+ str(sum_to-sum_from))
print ('sum_sum = '+ str(sum_sum))
print ('sum_action = ' + str(sum_action))
