/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "day.h"

bool_t
xdr_date (XDR *xdrs, date *objp)
{
	register int32_t *buf;


	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->years))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->months))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->days))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->leap))
				 return FALSE;
		} else {
			IXDR_PUT_LONG(buf, objp->years);
			IXDR_PUT_LONG(buf, objp->months);
			IXDR_PUT_LONG(buf, objp->days);
			IXDR_PUT_LONG(buf, objp->leap);
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->years))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->months))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->days))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->leap))
				 return FALSE;
		} else {
			objp->years = IXDR_GET_LONG(buf);
			objp->months = IXDR_GET_LONG(buf);
			objp->days = IXDR_GET_LONG(buf);
			objp->leap = IXDR_GET_LONG(buf);
		}
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->years))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->months))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->days))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->leap))
		 return FALSE;
	return TRUE;
}
