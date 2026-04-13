#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/ip.h>

static struct nf_hook_ops *pDanhSachHook = NULL;

static unsigned int KiemTraGoiTin(void *pPriv, struct sk_buff *pSocketBuffer, const struct nf_hook_state *pState)
{
    struct iphdr *pIpHeader;

    // Kiểm tra tính hợp lệ của socket buffer
    if (!pSocketBuffer)
        return NF_ACCEPT;

    // Trích xuất IP header
    pIpHeader = ip_hdr(pSocketBuffer);
    if (!pIpHeader)
        return NF_ACCEPT;

    // ===== YÊU CẦU 4: IN ĐỊA CHỈ IP =====
    // Sử dụng %pI4 để tự động format IP (truyền vào con trỏ của saddr và daddr)
    printk(KERN_INFO "My IP address = %pI4 AND Your IP address = %pI4\n", &pIpHeader->saddr, &pIpHeader->daddr);

    // Trả về ACCEPT để gói tin được lưu thông bình thường (bạn vẫn có thể ping được)
    return NF_ACCEPT;
}

static int __init KhoiTaoModule(void) {
    pDanhSachHook = (struct nf_hook_ops*)kcalloc(1, sizeof(struct nf_hook_ops), GFP_KERNEL);
    
    if (pDanhSachHook != NULL) {
        pDanhSachHook->hook = (nf_hookfn*)KiemTraGoiTin;
        // Đăng ký ở LOCAL_OUT (các gói tin đi ra từ máy Ubuntu) hoặc PRE_ROUTING đều được
        pDanhSachHook->hooknum = NF_INET_LOCAL_OUT; 
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