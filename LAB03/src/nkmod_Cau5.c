#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/ip.h>
#include <linux/string.h>

static struct nf_hook_ops *pDanhSachHook = NULL;

static unsigned int KiemTraGoiTin(void *pPriv, struct sk_buff *pSocketBuffer, const struct nf_hook_state *pState)
{
    struct iphdr *pIpHeader;
    char szDestIp[16] = {0};
    
    // IP của uit.edu.vn mà bạn đã nslookup được
    char szTargetIp[16] = "118.69.123.140"; 

    if (!pSocketBuffer)
        return NF_ACCEPT;

    pIpHeader = ip_hdr(pSocketBuffer);
    if (!pIpHeader)
        return NF_ACCEPT;

    // Lấy địa chỉ IP đích (Destination IP)
    snprintf(szDestIp, 16, "%pI4", &pIpHeader->daddr);

    // Kiểm tra xem IP đích có phải là IP của UIT không
    if (memcmp(&szDestIp, &szTargetIp, sizeof(szDestIp)) == 0) {
        printk(KERN_INFO "Netfilter: Cho phep goi tin di den uit.edu.vn (%s)\n", szDestIp);
        return NF_ACCEPT; // Chỉ ACCEPT duy nhất anh này
    }

    // DROP tất cả các gói tin có địa chỉ đích khác
    return NF_DROP;
}

static int __init KhoiTaoModule(void) {
    pDanhSachHook = (struct nf_hook_ops*)kcalloc(1, sizeof(struct nf_hook_ops), GFP_KERNEL);
    
    if (pDanhSachHook != NULL) {
        pDanhSachHook->hook = (nf_hookfn*)KiemTraGoiTin;
        
        // Bắt buộc dùng LOCAL_OUT vì đề bài ghi là "đi ra ngoài"
        pDanhSachHook->hooknum = NF_INET_LOCAL_OUT; 
        
        pDanhSachHook->pf = NFPROTO_IPV4;
        pDanhSachHook->priority = NF_IP_PRI_FIRST;
        
        nf_register_net_hook(&init_net, pDanhSachHook);
    }
    printk(KERN_INFO "Da tai Module: Chi cho phep di den UIT\n");
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