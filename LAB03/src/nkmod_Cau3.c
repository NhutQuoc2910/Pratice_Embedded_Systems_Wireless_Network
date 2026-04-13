#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <linux/udp.h>
#include <linux/string.h>

static struct nf_hook_ops *pDanhSachHook = NULL;

// Hàm xử lý chính: Kiểm tra và quyết định số phận gói tin
static unsigned int KiemTraGoiTinPort(void *pPriv, struct sk_buff *pSocketBuffer, const struct nf_hook_state *pState)
{
    struct iphdr *pIpHeader;
    struct tcphdr *pTcpHeader;
    struct udphdr *pUdpHeader;

    // Kiểm tra tính hợp lệ của socket buffer
    if(!pSocketBuffer)
        return NF_ACCEPT;

    // Trích xuất IP header
    pIpHeader = ip_hdr(pSocketBuffer);
    if (!pIpHeader)
        return NF_ACCEPT;

    // Xử lý nếu là gói tin TCP
    if (pIpHeader->protocol == IPPROTO_TCP) {
        // Trỏ tới TCP header dựa vào độ dài của IP header (ihl)
        pTcpHeader = (struct tcphdr *)((__u32 *)pIpHeader + pIpHeader->ihl);
        
        // Chuyển đổi port từ Network Byte Order sang dạng số nguyên bình thường để so sánh
        if (ntohs(pTcpHeader->dest) == 80) {
            printk(KERN_INFO "Da DROP goi tin TCP di den port 80\n");
            return NF_DROP;
        }
    }
    // Xử lý nếu là gói tin UDP
    else if (pIpHeader->protocol == IPPROTO_UDP) {
        // Trỏ tới UDP header
        pUdpHeader = (struct udphdr *)((__u32 *)pIpHeader + pIpHeader->ihl);
        
        if (ntohs(pUdpHeader->dest) == 80) {
            printk(KERN_INFO "Da DROP goi tin UDP di den port 80\n");
            return NF_DROP;
        }
    }

    // Cho qua tất cả các gói tin không khớp điều kiện
    return NF_ACCEPT;
}

static int __init KhoiTaoModule(void) {
    pDanhSachHook = (struct nf_hook_ops*)kcalloc(1,  sizeof(struct nf_hook_ops), GFP_KERNEL);
    
    if (pDanhSachHook != NULL) {
        pDanhSachHook->hook = (nf_hookfn*)KiemTraGoiTinPort;
        pDanhSachHook->hooknum = NF_INET_PRE_ROUTING; 
        pDanhSachHook->pf = NFPROTO_IPV4;
        pDanhSachHook->priority = NF_IP_PRI_FIRST;
        
        nf_register_net_hook(&init_net, pDanhSachHook);
    }
    return 0;
}

static void __exit HuyModule(void) {
    if(pDanhSachHook != NULL) {
        nf_unregister_net_hook(&init_net, pDanhSachHook);
        kfree(pDanhSachHook);
    }
    printk(KERN_INFO "Da go bo Module\n");
}

module_init(KhoiTaoModule);
module_exit(HuyModule);

MODULE_LICENSE("GPL");