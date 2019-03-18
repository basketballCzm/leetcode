# -*- coding: utf-8 -*-  
import requests
import json
import time

url = "https://nodes.get-scatter.com:443/v1/history/get_actions"

sum_action = 0;
first = 0
offset = 100

sum_delegatebw_net = 0.0
sum_delegatebw_cpu = 0.0
sum_undelegatebw_net = 0.0
sum_undelegatebw_cpu = 0.0
sum_sum = 0.0

def get_value(str):
    return float(str.split(" ")[0])

print (get_value("100000.00000 EOS"))
f = open("data3.md","wb")

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
        # "eosvoteproxy" == x["action_trace"]["receipt"]["receiver"]
        # 为自己抵押，如果使为他们抵押相当于转账给他人，并且根据源码，他人是不会被通知的。
        if "delegatebw" == x["action_trace"]["act"]["name"] and "eosio" == x["action_trace"]["receipt"]["receiver"] and x["action_trace"]["act"]["data"]["receiver"] == "gm3denbwguge":
            f.write (str(x["account_action_seq"]) + "\n")
            f.write (x["action_trace"]["receipt"]["receiver"] + "\n")
            f.write (x["action_trace"]["trx_id"] + "\n")
            if x["action_trace"]["act"]["data"]["stake_net_quantity"].split(" ")[1] == "EOS":
                sum_delegatebw_net += get_value(x["action_trace"]["act"]["data"]["stake_net_quantity"])
                sum_delegatebw_cpu += get_value(x["action_trace"]["act"]["data"]["stake_cpu_quantity"])
                f.write("stake_net_quantity " + x["action_trace"]["act"]["data"]["stake_net_quantity"] + "\n")
                f.write("stake_cpu_quantity " + x["action_trace"]["act"]["data"]["stake_cpu_quantity"] + "\n")
                f.write("from = " + x["action_trace"]["act"]["data"]["from"]+ "\n")
                f.write("receiver = " + x["action_trace"]["act"]["data"]["receiver"]+ "\n")
                f.write("***********************************\n\n")

        if "undelegatebw" == x["action_trace"]["act"]["name"] and "eosio" == x["action_trace"]["receipt"]["receiver"]:
            f.write (str(x["account_action_seq"]) + "\n")
            f.write (x["action_trace"]["receipt"]["receiver"]+ "\n")
            f.write (x["action_trace"]["trx_id"] + "\n")
            if x["action_trace"]["act"]["data"]["unstake_net_quantity"].split(" ")[1] == "EOS":
                sum_undelegatebw_net += get_value(x["action_trace"]["act"]["data"]["unstake_net_quantity"])
                sum_undelegatebw_cpu += get_value(x["action_trace"]["act"]["data"]["unstake_cpu_quantity"])
                f.write ("unstake_net_quantity " + x["action_trace"]["act"]["data"]["unstake_net_quantity"] + "\n")
                f.write ("unstake_cpu_quantity " + x["action_trace"]["act"]["data"]["unstake_cpu_quantity"] + "\n")
                f.write ("from = " + x["action_trace"]["act"]["data"]["from"] + "\n")
                f.write ("receiver = " + x["action_trace"]["act"]["data"]["receiver"] + "\n")
                f.write ("***********************************\n\n")        

    first = first + len_action
    sum_action = sum_action + len_action

f.close()  

print ("sum_delegatebw_net = " + str(sum_delegatebw_net))
print ("sum_delegatebw_cpu = " + str(sum_delegatebw_cpu))
print ("sum_undelegatebw_net = " + str(sum_undelegatebw_net))
print ("sum_undelegatebw_cpu = " + str(sum_undelegatebw_cpu))
print ("sum_delegatebw_net - sum_undelegatebw_net = " + str(sum_delegatebw_net-sum_undelegatebw_net))
print ("sum_delegatebw_cpu - sum_undelegatebw_cpu = " + str(sum_delegatebw_cpu-sum_undelegatebw_cpu))
print ("sum_action = " + str(sum_action))

