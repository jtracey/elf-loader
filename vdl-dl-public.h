#ifndef VDL_DL_PUBLIC_H
#define VDL_DL_PUBLIC_H

#include "macros.h"
#define _GNU_SOURCE 
#include <dlfcn.h> // for Dl_info
#include <link.h> // for struct dl_phdr_info

// these functions are called from libvdl.so
EXPORT void *vdl_dlopen_public (const char *filename, int flag);
EXPORT char *vdl_dlerror_public (void);
EXPORT void *vdl_dlsym_public (void *handle, const char *symbol, unsigned long caller);
EXPORT int vdl_dlclose_public (void *handle);
EXPORT int vdl_dladdr_public (const void *addr, Dl_info *info);
EXPORT void *vdl_dlvsym_public (void *handle, const char *symbol, const char *version, unsigned long caller);
EXPORT int vdl_dlinfo_public (void *handle, int request, void *p);
EXPORT void *vdl_dlmopen_public (Lmid_t lmid, const char *filename, int flag);
// create a new linkmap
EXPORT Lmid_t vdl_dl_lmid_new_public (int argc, char **argv, char **envp);
EXPORT int vdl_dl_add_callback_public (Lmid_t lmid, 
				       void (*cb) (void *handle, int event, void *context),
				       void *cb_context);
EXPORT int vdl_dl_add_lib_remap_public (Lmid_t lmid, const char *src, const char *dst);
EXPORT int vdl_dl_add_symbol_remap_public (Lmid_t lmid,
					   const char *src_name, 
					   const char *src_ver_name, 
					   const char *src_ver_filename, 
					   const char *dst_name,
					   const char *dst_ver_name,
					   const char *dst_ver_filename);

// This function is special: it is not called from ldso: it is
// used by vdl itself as the target of a redirection from every call to 
// dl_iterate_phdr
EXPORT int vdl_dl_iterate_phdr_public (int (*callback) (struct dl_phdr_info *info,
							size_t size, void *data),
				       void *data);
#endif /* VDL_DL_PUBLIC_H */
