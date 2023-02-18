//   Author: Unknown
//   Lab: Final2
//   Project: Final
//   File Name: binary_to_bcd.v
//   List of other files used: N/A
//-----------------------------------------------------------------------------
//   Description of the Code:
//   Converts the binary value to a bcd value.
//-----------------------------------------------------------------------------
//   Date: 02/17/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module binary_to_bcd
 #( parameter                W = 16)  // input width
  ( input      [W-1      :0] bin   ,  // binary
    output reg [W+(W-4)/3:0] bcd   ); // bcd {...,thousands,hundreds,tens,ones}

  integer i,j;

  always @(bin) 
	begin
    for(i = 0; i <= W+(W-4)/3; i = i+1) bcd[i] = 0;     // initialize with zeros
    bcd[W-1:0] = bin;                                   // initialize with input vector
    for(i = 0; i <= W-4; i = i+1)                       // iterate on structure depth
      for(j = 0; j <= i/3; j = j+1)                     // iterate on structure width
        if (bcd[W-i+4*j -: 4] > 4)                      // if > 4
          bcd[W-i+4*j -: 4] = bcd[W-i+4*j -: 4] + 4'd3; // add 3
  end

endmodule